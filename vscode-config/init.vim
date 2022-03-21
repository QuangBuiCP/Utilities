
set laststatus=2
set noshowmode

set mouse=a
set ruler
set showcmd
set shellslash
set cursorline

set autoindent
set smartindent

set expandtab
set tabstop=2
set softtabstop=2
set shiftwidth=2

set hlsearch
set smartcase
set ignorecase
set incsearc

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
augroup remember_folds
  autocmd!
  autocmd BufWinLeave * mkview
  autocmd BufWinEnter * silent! loadview
augroup END

" Quick shortcut (Far manager related)
nnoremap <F2> :w! <CR>
inoremap <F2> <ESC>:w!<CR>a
"nnoremap <F1> :wq! <CR>
"inoremap <F1> <ESC>:wq! <CR>
nnoremap <F4> :q<CR>
inoremap <F4> <ESC>:q<CR>a

" Ctrl + S for save (?)
nnoremap <C-s> :w!<CR>
inoremap <C-s> <ESC>:w!<CR>a

" Navigation keybind
nnoremap j <LEFT>
nnoremap i <UP>
nnoremap k <DOWN>
nnoremap l <RIGHT>
nnoremap q b
nnoremap u 0
nnoremap 0 $
vnoremap u 0
vnoremap 0 $
inoremap <A-j> <LEFT>
inoremap <A-i> <UP>
inoremap <A-k> <DOWN>
inoremap <A-l> <RIGHT>
vnoremap j <LEFT>
vnoremap i <UP>
vnoremap k <DOWN>
vnoremap l <RIGHT>

" Use "a" as insert mode instead of "i"
nnoremap a i
" Use "f" as insert mode instead of "a"
nnoremap f a

" Switch to command mode
inoremap <A-u> <ESC>:
nnoremap <A-u> :

" Undo / Redo
nnoremap <C-Z> u
inoremap <C-Z> <C-O>u
inoremap <C-R> <ESC><C-R><CR>a

" CTRL-X and SHIFT-Del are Cut
vnoremap <C-X> "+x
vnoremap <S-Del> "+x

" CTRL-C and CTRL-Insert are Copy
vnoremap <C-C> "+y
vnoremap <C-Insert> "+y

" CTRL-V and SHIFT-Insert are Paste
map <C-V> "+gP
map <S-Insert> "+gP

cmap <C-V> <C-R>+
cmap <S-Insert> <C-R>+

" Pasting blockwise and linewise selections is not possible in Insert and
" Visual mode without the +virtualedit feature.  They are pasted as if they
" were characterwise instead.
" Uses the paste.vim autoload script.

exe 'inoremap <script> <C-V>' paste#paste_cmd['i']
exe 'vnoremap <script> <C-V>' paste#paste_cmd['v']

imap <S-Insert> <C-V>
vmap <S-Insert> <C-V>

" Select all
inoremap <C-a> <ESC>ggVG
nnoremap <C-a> ggVG

" Delete line
nnoremap <C-y> dd
inoremap <C-y> <ESC>dda



nnoremap t f
