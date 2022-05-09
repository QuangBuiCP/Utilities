
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
