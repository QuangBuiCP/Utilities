for setting_file in split(glob(stdpath('config').'/settings/*.vim'))
	execute 'source' setting_file
endfor

for setting_file in split(glob(stdpath('config').'/settings/*.lua'))
	execute 'source' setting_file
endfor