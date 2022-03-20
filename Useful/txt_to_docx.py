from docx import Document
import glob
import os
 
 
doc = Document()
 
files = glob.glob("*.txt")
print(files)
filename = input("File to convert (without \".txt\"): ")
 
with open(filename + ".txt", 'r', encoding='utf-8') as openfile:
  line = openfile.read()
  doc.add_paragraph(line)
  doc.save(filename + ".docx")

print("Program finished")
