" vim setting
colorscheme desert 
syntax enable
set noerrorbells
set nobackup
setlocal noswapfile
" set number
set shortmess=atI " eliminate the welcome interface
set lbr
set magic " show match
set showmatch  " match setting 
set matchtime=2 
set textwidth=80 " set line limit
set incsearch " incremental searches
filetype plugin on
filetype indent on
set gcr=a:block-blinkon0 " mouse don't shine
set tabstop=4
set autoindent
set smartindent
set softtabstop=4 
set shiftwidth=4
set noexpandtab
set cindent
set smarttab
set nowrap
set laststatus=2 " show the status line
set ruler
set wildmenu
set cmdheight=1


" Toggle Menu and Toolbar
set guioptions-=r
set guioptions-=m
set guioptions-=T
map <silent> <F2> :if &guioptions =~# 'T' <Bar>
        \set guioptions-=T <Bar>
        \set guioptions-=m <bar>
    \else <Bar>
        \set guioptions+=T <Bar>
        \set guioptions+=m <Bar>
    \endif<CR>


" keybinding
map <f5> :w<CR>:!gcc -g -Wall %<CR><CR>
map <C-f5> :!./a.out<CR><CR>
