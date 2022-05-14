require('bufferline').setup {
	options = {
		mode = "buffers",
		offsets = { { filetype = "NvimTree", text = "", padding = 1 } },
		close_command = "bdelete! %d",       -- can be a string | function, see "Mouse actions"
		right_mouse_command = "bdelete! %d", -- can be a string | function, see "Mouse actions"
		left_mouse_command = "buffer %d",    -- can be a string | function, see "Mouse actions"
		middle_mouse_command = nil,          -- can be a string | function, see "Mouse actions" 
		color_icons = true,
		buffer_close_icon = "",
		modified_icon = "●",
		close_icon = "",
		show_close_icon = true,
		left_trunc_marker = "",
		right_trunc_marker = "",
		max_name_length = 14,
		max_prefix_length = 11,
		tab_size = 16,
		show_tab_indicators = true,
		enforce_regular_tabs = false,
		view = "multiwindow",
		show_buffer_close_icons = true,
		separator_style = "thin",
		always_show_bufferline = true,
		diagnostics = false,
		themable = true,

		custom_filter = function(buf_number)
			-- Func to filter out our managed/persistent split terms
			local present_type, type = pcall(function()
				return vim.api.nvim_buf_get_var(buf_number, "term_type")
			end)

			if present_type then
				if type == "vert" then
					return false
				elseif type == "hori" then
					return false
				end
				return true
			end

			return true
		end,
	},
	custom_areas = {
		right = function()
			local result = {}
			local error = vim.lsp.diagnostic.get_count(0, [[Error]])
			local warning = vim.lsp.diagnostic.get_count(0, [[Warning]])
			local info = vim.lsp.diagnostic.get_count(0, [[Information]])
			local hint = vim.lsp.diagnostic.get_count(0, [[Hint]])

			if error ~= 0 then
				table.insert(result, {text = "  " .. error}) -- , guifg = "#EC5241"})
			end

			if warning ~= 0 then
				table.insert(result, {text = "  " .. warning}) -- , guifg = "#EFB839"})
			end

			if hint ~= 0 then
				table.insert(result, {text = "  " .. hint}) -- , guifg = "#A3BA5E"})
			end

			if info ~= 0 then
				table.insert(result, {text = "  " .. info}) -- , guifg = "#7EA9A7"})
			end
			return result
		end,
	}
}
