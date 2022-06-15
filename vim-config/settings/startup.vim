set guicursor=n-v-c-sm:block,i-ci-ve:ver20-cursor,r-cr-o:hor20
set guifont=Bitstream\ Vera\ Sans\ Mono:h15

set t_Co=256
colorscheme onedark
"colorscheme catppuccin
set cmdheight=1

set laststatus=2
set noshowmode

set mouse=a
set ruler
set showcmd
set shellslash
set cursorline

set autoindent
set smartindent

set tabstop=4
set softtabstop=4
set shiftwidth=4



set hlsearch
set smartcase
set ignorecase
set incsearch

set undolevels=1000
set backspace=indent,eol,start	

syntax on

set nu
augroup numbertoggle
  autocmd!
  autocmd BufEnter,FocusGained,InsertLeave * set rnu
  autocmd BufLeave,FocusLost,InsertEnter * set nornu
augroup END

" Uncomment the following to have Vim jump to the last position when
" reopening a file
if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

" Save file folding
" 'mkview' to save the fold
" 'loadview' to load the last saved fold
" .........

set termguicolors
lua require'colorizer'.setup()