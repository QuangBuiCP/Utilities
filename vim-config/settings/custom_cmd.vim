" Copy all by :cal
cnoreabbrev cal %y+

" Copy file's path to clipboard with :pat
if has('win32')
  cnoreabbrev pat let @+=substitute(expand("%:p"), "/", "\\", "g")
else
  cnoreabbrev pat let @+=expand("%:p")
endif
