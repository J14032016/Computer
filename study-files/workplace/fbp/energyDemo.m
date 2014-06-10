energy = load('Th232_11_MVT_energy_corrected.txt');
energy = energy(~isnan(energy)); % take out  not a number
energy = energy(~isinf(energy)); % take out the infinite elements
energy = energy*661.5 ./ 1.25e6;
energy = energy(energy<=3000);
xx = min(energy):max(energy); % set the x axis
yy = hist(energy,xx); % get the value
subplot(2,2,1)
plot(xx,yy),title('Original');

% smooth
yy_smooth = smooth(yy,50); % use smooth function to smooth the data
yy_smooth = yy_smooth'; % smooth function rotate the data, now rotate back
subplot(2,2,2)
plot(xx,yy_smooth),title('Smooth');
hold on % hold on the figure , then add the peaks 

% find the peaks
[~,M] = size(xx);
setSize = 50;
pks = zeros(10,2);
pks_size = 1;
% do loop : take out 20 numbers, find the biggest one
% if it's in the center,it's a peak, then move forward
for i=11:(M-10) 
    for j=(i-10):(i+10)
        tmp = yy_smooth(1,i-10:i+10);
        if (max(tmp)==yy_smooth(1,i))&&(max(tmp)>=setSize);
            pks(pks_size,1) = xx(1,i);
            pks(pks_size,2) = yy_smooth(1,i);
            pks_size = pks_size+1;
            break;
        end
    end
end

pks_x = pks(:,1);
pks_y = pks(:,2);
plot(pks_x,pks_y,'*');