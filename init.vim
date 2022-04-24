call plug#begin('~/.vim/plugged')

Plug 'itchyny/lightline.vim'
Plug 'sonph/onehalf', { 'rtp': 'vim' }

Plug 'nvim-treesitter/nvim-treesitter', { 'do': ':TSUpdate' }
Plug 'p00f/nvim-ts-rainbow'
Plug 'norcalli/nvim-colorizer.lua'
Plug 'joshdick/onedark.vim'

Plug 'neovim/nvim-lspconfig'

let g:lightline = {
      \ 'colorscheme': 'onehalfdark',
      \ 'active': {
      \   'right': [ [ 'lineinfo' ],
      \              [ 'percent' ],
      \              [ 'fileformat', 'fileencoding', 'filetype', 'charvaluehex' ] ]
      \ },
      \ 'component': {
      \   'charvaluehex': '0x%B'
      \ },
      \ }



call plug#end()

set termguicolors
lua require'colorizer'.setup()

lua <<OEF

--- LSP server

require'lspconfig'.clangd.setup{}

--- End of LSP server

-- treesitter
require('nvim-treesitter.configs').setup {
    ensure_installed = "maintained",
    highlight = { 
        enable = true,
        custom_captures = {
            ["character"] = "TSString",
            ["operator"] = "TSStringEscape",
            ["constructor"] = "TSFunction",
        }
    },
    rainbow = {
        enable = true,
        extended_mode = true,
        max_file_lines = nil,

        -- nvim-ts-rainbow
        colors = {
            "#e06c75",
            "#98c379",
            "#d19a66",
            "#61afef",
            "#c678dd",
            "#56b6c2",
            "#828791",
        }
        -- end of nvim-ts-rainbow
    }
}
-- end of treesitter

OEF

let g:python3_host_prog = 'C:/Users/Admin/AppData/Local/Microsoft/WindowsApps/python.exe'

set guicursor=n-v-c-sm:block,i-ci-ve:ver20-cursor,r-cr-o:hor20
set guifont=Consolas:h15

set t_Co=256
colorscheme onedark

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
augroup remember_folds
  autocmd!
  autocmd BufWinLeave * mkview
  autocmd BufWinEnter * silent! loadview
augroup END

" LSP for Clangd
if executable('clangd')
    augroup lsp_clangd
        autocmd!
        autocmd User lsp_setup call lsp#register_server({
                    \ 'name': 'clangd',
                    \ 'cmd': {server_info->['clangd']},
                    \ 'whitelist': ['c', 'cpp', 'objc', 'objcpp'],
                    \ })
        autocmd FileType c setlocal omnifunc=lsp#complete
        autocmd FileType cpp setlocal omnifunc=lsp#complete
        autocmd FileType objc setlocal omnifunc=lsp#complete
        autocmd FileType objcpp setlocal omnifunc=lsp#complete
    augroup end
endif


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
autocmd filetype cpp nnoremap <F9> :w <bar> !start pauser com %:r && echo.<CR>
" autocmd filetype cpp nnoremap <F10> :!start pauser !%:r && echo.<CR>
autocmd filetype cpp inoremap <F9> <ESC>:w <bar> !start pauser com %:r && echo.<CR>
" autocmd filetype cpp inoremap <F10> <ESC>:!start pauser !%:r && echo.<CR>