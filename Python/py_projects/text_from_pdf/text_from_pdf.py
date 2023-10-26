pip install PyPDF2 //to install PyPDF2

//extracting text from pdf
import PyPDF2
pdfFile=open('cat.pdf','rb')
pdfReader=PyPDF2.PdfFileReader(pdfFile)
page1=pdfReader.getPage(2) //2 is the index of the page on the cat.pdf
//print(page1.extractText()) //to print the extracted text of page
page2=pdfReader.getPage(3) //3 is the index of the page of the pdf 
//print(page2.extractText())
page3=pdfReader.getPage(4)
//print(page3.extractText())

//merging the extracted pages of the pdf
pdfWriter=PyPDF2.PdfFileWriter()
pdfWriter.addPage(page1)
pdfWriter.addPage(page2)
pdfWriter.addPage(page3) 
output=open('page.pdf','wb')//all the 3 extracted pages are merged to form another pdf
pdfWriter.write(output)
output.close()