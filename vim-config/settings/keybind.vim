
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

noremap <C-k> <C-d>
noremap <C-i> <C-u>


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

" Comment line of code in C++ with "Ctrl+e"
autocmd filetype cpp nnoremap <C-e> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $
autocmd filetype cpp vnoremap <C-e> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $

" Pasting blockwise and linewise selections is not possible in Insert and
" Visual mode without the +virtualedit feature.  They are pasted as if they
" were characterwise instead.
" Uses the paste.vim autoload script.

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
imap <S-Insert> <C-V>
vmap <S-Insert> <C-V>

exe 'inoremap <script> <C-V>' paste#paste_cmd['i']
exe 'vnoremap <script> <C-V>' paste#paste_cmd['v']

" Select all
inoremap <C-a> <ESC>ggVG
nnoremap <C-a> ggVG

" Switch to UTF16-LE by :f16
cnoreabbrev f16 e ++enc=utf-16le

" Delete line
nnoremap <C-y> dd
inoremap <C-y> <ESC>dda

nnoremap t f

" Build and run for *.cpp
autocmd filetype cpp nnoremap <F9> :w <bar> !start pauser com %:r && echo.<CR>
" autocmd filetype cpp nnoremap <F10> :!start pauser !%:r && echo.<CR>
autocmd filetype cpp inoremap <F9> <ESC>:w <bar> !start pauser com %:r && echo.<CR>
" autocmd filetype cpp inoremap <F10> <ESC>:!start pauser !%:r && echo.<CR>