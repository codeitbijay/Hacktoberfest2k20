from bs4 import BeautifulSoup
import requests 
import os 
from fpdf import FPDF
import img2pdf 
from PIL import Image 
from time import sleep

#url to the slide
source = requests.get("https://www.slideshare.net/SusanAragon1/normalized-difference-vegetation-index-ndvi?qid=9c7107c1-01f8-48cd-9464-0e5e4e710699&v=&b=&from_search=3").text
soup = BeautifulSoup(source, 'lxml')

def get_img():
    img = soup.find_all('img', class_ = "slide_image")
    imglist = []
    for image in img: 
        img_url = image.get('data-full').split('?')[0] 
        imglist.append(img_url)
    toPdf(imglist)
    return imglist

def toPdf(imglist):
    img_data = []
    for i in range(0, len(imglist)):
        imgsrc = imglist[i]
        img_data.append(requests.get(imgsrc).content)
        sleep(1)
        print("Processing...")
    with open("slide.pdf", "wb") as file: 
        for f_img in img_data:
            pdf_bytes = img2pdf.convert(img_data)
            file.write(pdf_bytes) 
    file.close() 

get_img()
