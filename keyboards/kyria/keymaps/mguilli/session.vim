let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/qmk_firmware/keyboards/kyria/keymaps/mguilli
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/keymap.c
badd +1 ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/config.h
badd +0 ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/rules.mk
argglobal
%argdel
edit ~/qmk_firmware/keyboards/kyria/keymaps/mguilli/keymap.c
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
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
exe '1resize ' . ((&lines * 34 + 26) / 52)
exe '2resize ' . ((&lines * 13 + 26) / 52)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
exe '3resize ' . ((&lines * 13 + 26) / 52)
exe 'vert 3resize ' . ((&columns * 104 + 104) / 209)
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
let s:l = 1 - ((0 * winheight(0) + 17) / 34)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
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
let s:l = 1 - ((0 * winheight(0) + 6) / 13)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 03|
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
let s:l = 1 - ((0 * winheight(0) + 6) / 13)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
exe '1resize ' . ((&lines * 34 + 26) / 52)
exe '2resize ' . ((&lines * 13 + 26) / 52)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
exe '3resize ' . ((&lines * 13 + 26) / 52)
exe 'vert 3resize ' . ((&columns * 104 + 104) / 209)
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
