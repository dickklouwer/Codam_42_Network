#!/usr/bin/python3

import os

def move_up(path: str, up_count: int) ->str:
	for i in range(up_count + 1):
		path = os.path.dirname(path)
	return path

template_path = os.path.join(move_up(__file__, 1), "www/bmi_calculator/bmi_result.html")
f = open(template_path, "r")
html_template = f.read()

query_params = {k:v for k, v in [val.split("=") for val in os.environ["QUERY_STRING"].split("&")]}

query_params["result"] = int(query_params["weight"]) / (int(query_params["height"]) / 100) ** 2

for k, v in query_params.items():
    html_template = html_template.replace(f"%{k.upper()}%", str(v))

print(html_template)