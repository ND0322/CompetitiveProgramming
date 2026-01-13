import re 

s = "amish  tomato ketchup  for canning"

s = re.sub(r"\s+", " ", s).strip()

print(s)