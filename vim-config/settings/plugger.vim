call plug#begin('~/.vim/plugged')

Plug 'kyazdani42/nvim-web-devicons' " Recommended (for coloured icons)
Plug 'akinsho/bufferline.nvim', { 'tag': 'v2.*' }
Plug 'vim-airline/vim-airline'
Plug 'lukas-reineke/indent-blankline.nvim'

Plug 'nvim-treesitter/nvim-treesitter', { 'do': ':TSUpdate' }
Plug 'norcalli/nvim-colorizer.lua'
Plug 'joshdick/onedark.vim'
"Plug 'catppuccin/nvim', {'as': 'catppuccin'}

Plug 'neovim/nvim-lspconfig'
Plug 'neoclide/coc.nvim', {'branch': 'release'}

call plug#end()
