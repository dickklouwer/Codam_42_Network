#!/usr/bin/python3

import os


def move_up(path: str, up_count: int) ->str:
	for i in range(up_count + 1):
		path = os.path.dirname(path)
	return path

file  = move_up(__file__, 1)
print(file)
abs_path = os.path.join(file, "uploads")

dir_content = os.listdir(abs_path)

for el in dir_content:
    print(f"<img src=\"{abs_path + '/' + el}\">")