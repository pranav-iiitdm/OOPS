import tkinter as tk

gpa=tk.Tk()

gpa.title("MARKSHEET")

gpa.geometry("600x300")

def check_grade(grd):

    if grd=="S":
        return 10
    if grd=="A":
        return 9
    if grd=="B":
        return 8
    if grd=="C":
        return 7
    if grd=="D":
        return 6
    if grd=="E":
        return 5
    if grd=="U" or grd=="W" or grd=="I":
        return 0

def calculate_gpa():
    g1=grd1.get()
    g1=check_grade(g1)

    g2=grd2.get()
    g2=check_grade(g2)

    g3=grd3.get()
    g3=check_grade(g3)

    g4=grd4.get()
    g4=check_grade(g4)

    cr1=g1*4
    cr2=g2*4
    cr3=g3*3
    cr4=g4*4

    c1.config(text=cr1)
    c2.config(text=cr2)
    c3.config(text=cr3)
    c4.config(text=cr4)

    tcrd=cr1+cr2+cr3+cr4
    tc.config(text=tcrd)

    s=tcrd/15
    s=round(s,2)
    sg.config(text=s)

#NAME

name_label=tk.Label(gpa,text="Name")
name_label.grid(row=0,column=0)

name_entry=tk.Entry(gpa)
name_entry.grid(row=0,column=1)

#ROLL NO

roll_label=tk.Label(gpa,text="Roll No")
roll_label.grid(row=1,column=0)

roll_entry=tk.Entry(gpa)
roll_entry.grid(row=1,column=1)

#SNO

srno=tk.Label(gpa,text="S No")
srno.grid(row=4,column=0)

srno1=tk.Label(gpa,text="1")
srno1.grid(row=5,column=0)

srno2=tk.Label(gpa,text="2")
srno2.grid(row=6,column=0)

srno3=tk.Label(gpa,text="3")
srno3.grid(row=7,column=0)

srno4=tk.Label(gpa,text="4")
srno4.grid(row=8,column=0)

#SUBJECT

subject=tk.Label(gpa,text="Subject")
subject.grid(row=4,column=1)

subject1=tk.Label(gpa,text="CS 201")
subject1.grid(row=5,column=1)

subject2=tk.Label(gpa,text="CS 202")
subject2.grid(row=6,column=1)

subject3=tk.Label(gpa,text="MA 201")
subject3.grid(row=7,column=1)

subject4=tk.Label(gpa,text="EC 201")
subject4.grid(row=8,column=1)

#GRADE

grade=tk.Label(gpa,text="Grade")
grade.grid(row=4,column=2)

grd1=tk.Entry(gpa)
grd1.grid(row=5,column=2)

grd2=tk.Entry(gpa)
grd2.grid(row=6,column=2)

grd3=tk.Entry(gpa)
grd3.grid(row=7,column=2)

grd4=tk.Entry(gpa)
grd4.grid(row=8,column=2)

#SUB CREDIT

subc=tk.Label(gpa,text="Sub Credit")
subc.grid(row=4,column=3)

subc1=tk.Label(gpa,text="4")
subc1.grid(row=5,column=3)

subc2=tk.Label(gpa,text="4")
subc2.grid(row=6,column=3)

subc3=tk.Label(gpa,text="3")
subc3.grid(row=7,column=3)

subc4=tk.Label(gpa,text="4")
subc4.grid(row=8,column=3)

#CREDIT

credit=tk.Label(gpa,text="Credits Obtained")
credit.grid(row=4,column=4,padx=10)

c1=tk.Label(gpa,text="")
c1.grid(row=5,column=4)

c2=tk.Label(gpa,text="")
c2.grid(row=6,column=4)

c3=tk.Label(gpa,text="")
c3.grid(row=7,column=4)

c4=tk.Label(gpa,text="")
c4.grid(row=8,column=4)

#TOTAL

total=tk.Label(gpa,text="Total Credits")
total.grid(row=9,column=3)

tc=tk.Label(gpa,text="")
tc.grid(row=9,column=4)

#SGPA

sgpa=tk.Label(gpa,text="SGPA")
sgpa.grid(row=10,column=3)

sg=tk.Label()
sg.grid(row=10,column=4)

calculate=tk.Button(gpa,text="SUBMIT",bg="green",command=calculate_gpa)
calculate.grid(row=15,column=2,pady=10)

gpa.mainloop()