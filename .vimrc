""" Default config

" Vim with all enhancements
source $VIMRUNTIME/vimrc_example.vim

" Use the internal diff if available.
" Otherwise use the special 'diffexpr' for Windows.
if &diffopt !~# 'internal'
  set diffexpr=MyDiff()
endif
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg1 = substitute(arg1, '!', '\!', 'g')
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg2 = substitute(arg2, '!', '\!', 'g')
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let arg3 = substitute(arg3, '!', '\!', 'g')
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      if empty(&shellxquote)
        let l:shxq_sav = ''
        set shellxquote&
      endif
      let cmd = '"' . $VIMRUNTIME . '\diff"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  let cmd = substitute(cmd, '!', '\!', 'g')
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3
  if exists('l:shxq_sav')
    let &shellxquote=l:shxq_sav
  endif
endfunction



""" My config

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

" Comment line of code in C++ with "Ctrl+e"
autocmd filetype cpp nnoremap <C-e> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $
autocmd filetype cpp vnoremap <C-e> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $

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

" Copy all by :cal
cnoreabbrev cal %y+

" Copy file's path to clipboard with :pat
if has('win32')
  cnoreabbrev pat let @+=substitute(expand("%:p"), "/", "\\", "g")
else
  cnoreabbrev pat let @+=expand("%:p")
endif

" Switch to UTF16-LE by :f16
cnoreabbrev f16 e ++enc=utf-16le

" Delete line
nnoremap <C-y> dd
inoremap <C-y> <ESC>dda

nnoremap t f

" Build and run for *.cpp
autocmd filetype cpp nnoremap <F9> :w <bar> !com %:r && echo.<CR>
autocmd filetype cpp nnoremap <F10> :!%:r && echo.<CR>
autocmd filetype cpp inoremap <F9> <ESC>:w <bar> !com %:r && echo.<CR>
autocmd filetype cpp inoremap <F10> <ESC>:!%:r && echo.<CR>

set guifont=Consolas:h15