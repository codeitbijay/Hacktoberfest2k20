from PyPDF2 import PdfFileWriter, PdfFileReader
def secure_pdf(file, password):
    parser = PdfFileWriter()
    pdf = PdfFileReader(file)
    for page in range(pdf.numPages):
        parser.addPage(pdf.getPage(page))
    parser.encrypt(password)
    with open(f"new_{file}", "wb") as f:
        parser.write(f)
        f.close()
    print(f"Done! Password protected file new_{file} created.")

if __name__ == "__main__":
    file = "file_name.pdf" # file in same folder
    password = "set_a_password"
    secure_pdf(file,password)