import tkinter as tk

bmi=tk.Tk()

ans=0

def calculate_bmi():
    h=float(height_entry.get())
    w=float(weight_entry.get())
    ans=w/(h*h)
    ans=round(ans,1)

    output=str(ans) 

    bmi_label.config(text=output)

    return

bmi.title("BMI Calculator ")

bmi.geometry("400x100")

h=tk.StringVar()
w=tk.StringVar()

height=tk.Label(bmi,text="Height ( in metre ) ")
height.grid(row=0,column=0)

height_entry=tk.Entry(bmi)
height_entry.grid(row=0,column=1)

weight=tk.Label(bmi,text="Weight ( in Kg ) ")
weight.grid(row=1,column=0)

weight_entry=tk.Entry(bmi)
weight_entry.grid(row=1,column=1)

calculate=tk.Button(bmi,text="Calculate",command=calculate_bmi)
calculate.grid(row=5,column=3)

bmiLabel=tk.Label(bmi,text="BMI")
bmiLabel.grid(row=3,column=0)

bmi_label=tk.Label(bmi)
bmi_label.grid(row=3,column=1)

bmi.mainloop()