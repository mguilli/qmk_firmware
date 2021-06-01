let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/qmk_firmware/keyboards/kyria/keymaps/mguilli
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +11 ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/keymap.c
badd +1 ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/config.h
badd +1 ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/rules.mk
badd +0 keymap.h
argglobal
%argdel
edit ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/keymap.c
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd w
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 30 + 23) / 47)
exe 'vert 1resize ' . ((&columns * 156 + 105) / 211)
exe '2resize ' . ((&lines * 30 + 23) / 47)
exe 'vert 2resize ' . ((&columns * 54 + 105) / 211)
exe '3resize ' . ((&lines * 12 + 23) / 47)
exe 'vert 3resize ' . ((&columns * 105 + 105) / 211)
exe '4resize ' . ((&lines * 12 + 23) / 47)
exe 'vert 4resize ' . ((&columns * 105 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
argglobal
if bufexists("keymap.h") | buffer keymap.h | else | edit keymap.h | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 30 - ((29 * winheight(0) + 15) / 30)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
30
normal! 07|
wincmd w
argglobal
if bufexists("~/qmk_firmware/keyboards/kyria/keymaps/mguilli/config.h") | buffer ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/config.h | else | edit ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/config.h | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 23 - ((7 * winheight(0) + 6) / 12)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
23
normal! 028|
wincmd w
argglobal
if bufexists("~/qmk_firmware/keyboards/kyria/keymaps/mguilli/rules.mk") | buffer ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/rules.mk | else | edit ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/rules.mk | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 6) / 12)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
exe '1resize ' . ((&lines * 30 + 23) / 47)
exe 'vert 1resize ' . ((&columns * 156 + 105) / 211)
exe '2resize ' . ((&lines * 30 + 23) / 47)
exe 'vert 2resize ' . ((&columns * 54 + 105) / 211)
exe '3resize ' . ((&lines * 12 + 23) / 47)
exe 'vert 3resize ' . ((&columns * 105 + 105) / 211)
exe '4resize ' . ((&lines * 12 + 23) / 47)
exe 'vert 4resize ' . ((&columns * 105 + 105) / 211)
tabnext 1
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=filnxtToOFc
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
