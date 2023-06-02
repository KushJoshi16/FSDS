import re

def replacetext(search_text,replace_text):

	with open('input.txt','r+') as f:
		file = f.read()
		
		file = re.sub(search_text, replace_text, file)
		f.seek(0)
		f.write(file)
		f.truncate()
	return "Text replaced"



# search_text = r'[\[\]]'

# replace_text = " "

print(replacetext(r'[\[\]]',''))
print(replacetext(r',',' '))
