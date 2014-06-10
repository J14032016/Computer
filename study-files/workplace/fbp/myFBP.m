J = 128;
P = phantom(J);
theta = 1:180;

% 1) projection
[R, xp] = radon(P, theta); % xp is a vector contain radial coordinates to each row of R
% [R, xp] = myProjection(P, theta);

xp_offset = round(size(R,1)/2);
[N, K] = size(R); % 185 180
tmpImg = zeros(J);
width = 2^nextpow2(N);  % get width for FFT  width = 2^8 = 256
filtered = zeros(width, K);

% create the filter in frequency domain : RL
filter = 2*[0:(width/2-1), width/2:-1:1]'/width;  % R256 C1

% 2) perform FFT zero pad to width is done by FFT function
proj_fft = fft(R, width);   % R256 C180

% 3) do the filtering in frequence domain
% Element by element multiplication
for i = 1:K
    filtered(:,i) = proj_fft(:,i).*filter;
end

% 4) preform IFFT on product of step 3)
% the imaginary part is zero in theory
 proj = real(ifft(filtered));

% 5) backprojection   integrate the IFFT
% set center axis for backprojection
for i = 1:K
    Q = proj(:, i); % get filtered projection for current angle
    rad = theta(i)*pi/180; % convert current angle to radians
%{
    for y = 1:J
        for x = 1:J
            t = round((y-J/2)*cos(rad) - (x-J/2)*sin(rad));
            tmpImg(x,y) = tmpImg(x,y) + Q(t+xp_offset);
        end
    end
%}
    for y = (-J/2+1):J/2
        for x = (-J/2+1):J/2
            t = round(y*cos(rad)-x*sin(rad));
            tmpImg(x+J/2,y+J/2) = tmpImg(x+J/2,y+J/2)+Q(t+xp_offset);
        end
    end
end

img = (pi/K)*tmpImg;

subplot(1, 3, 1), imshow(P), title('Original')
subplot(1, 3, 2), imshow([R, xp]), title('Radon Transform')
subplot(1, 3, 3), imshow(img), title('FBP')