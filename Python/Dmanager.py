import glob
import os


doc_dir='/home/shan/Documents/'
music_dir='home/shan/Music/'
video_dir='home/shan/Videos/'



list=['pdf','mp3','mp4','jpg']
files_dict={}
for filetype in list:
	files_dict[filetype]=(glob.glob('*.'+filetype))

cwd=os.getcwd()

for type,files in files_dict.items():
	if type=='pdf':
		dir=doc_dir
	elif type=='mp3':
		dir=music_dir
	elif type=='mp4':
		dir=video_dir
	for file in files:
		os.replace(cwd+'/'+file,docdir+file)
		print('file '+file+' moved to '+docdir)
