import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from sorts import VisualSorts

def sort():
    # Retrieve input data from the entry widget
    input_data = entry.get()
    # Convert input string to a list of integers
    data_list = list(map(int, input_data.split(',')))

    # Create an instance of VisualSorts
    data = VisualSorts(data_list, ax, matplot_canva)
    
    # Get the selected algorithm from the option menu
    algo_choice = algorithm_var.get()
    
    # Get the method dynamically based on the selected algorithm
    algorithm_method = getattr(data, algo_choice, None)
    
    # Call the method if it exists
    if algorithm_method is not None and algo_choice != "quicksort":
        algorithm_method()
    elif algorithm_method is not None and algo_choice == "quicksort":
        algorithm_method(0, len(data.data) - 1)

def on_entry_click(event):
    # Handle the entry click event
    if entry.get() == placeholder:
        entry.delete(0, "end")
        entry.config(fg='white')  # Set text color to black

def on_entry_focus_out(event):
    # Handle the entry focus out event
    if not entry.get():
        entry.insert(0, placeholder)
        entry.config(fg='grey')  # Set text color to grey

# Create the main application window
root = tk.Tk()
root.title("Sorting Algorithm Visualizer")

# Create an empty canvas
canvas = tk.Canvas(root, width=400, height=300)
canvas.pack()

# Create an option menu for selecting sorting algorithms
algorithm_var = tk.StringVar(root)
algorithm_var.set("Select an Algorithm")
algorithm_menu = tk.OptionMenu(root, algorithm_var, "quicksort", "selectionsort", "bubblesort", "mergesort")
canvas.create_window(200, 100, window=algorithm_menu)

# Create an entry widget for input data
placeholder = "Input numbers for sorting"
entry = tk.Entry(root, fg='grey')
entry.insert(0, placeholder)
entry.bind("<FocusIn>", on_entry_click)
entry.bind("<FocusOut>", on_entry_focus_out)
canvas.create_window(200, 140, window=entry)

# Create a button for triggering the sorting process
sort_button = tk.Button(text='Sort', command=sort)
canvas.create_window(200, 180, window=sort_button)

# Create a matplotlib canvas for visualization
fig, ax = plt.subplots(figsize=(5, 5))
matplot_canva = FigureCanvasTkAgg(fig, master=root)
matplot_canva.get_tk_widget().pack()

# Start the Tkinter event loop
root.mainloop()