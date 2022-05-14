call plug#begin('~/.vim/plugged')

Plug 'sonph/onehalf', { 'rtp': 'vim' }
Plug 'kyazdani42/nvim-web-devicons' " Recommended (for coloured icons)
Plug 'akinsho/bufferline.nvim', { 'tag': 'v2.*' }
Plug 'vim-airline/vim-airline'
Plug 'lukas-reineke/indent-blankline.nvim'

Plug 'nvim-treesitter/nvim-treesitter', { 'do': ':TSUpdate' }
Plug 'p00f/nvim-ts-rainbow'
Plug 'norcalli/nvim-colorizer.lua'
Plug 'joshdick/onedark.vim'

Plug 'neovim/nvim-lspconfig'
Plug 'neoclide/coc.nvim', {'branch': 'release'}

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
