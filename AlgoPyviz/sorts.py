import time
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

class VisualSorts:

    def __init__(self, data, ax, canvas):
        self.data = data
        self.ax = ax
        self.canvas = canvas

    def __plot(self):
        self.ax.clear()
        x = range(len(self.data))
        self.ax.bar(x, self.data, color='maroon', align='center', width=0.6)
        self.canvas.draw()
        self.canvas.get_tk_widget().update_idletasks()
        time.sleep(0.2)

    def selectionsort(self):
        l = len(self.data)
        for n in range(l ):
            print(self.data)
            self.__plot()
            smallpos = n
            for i in range(n, l):
                if self.data[i] < self.data[smallpos]:
                    smallpos = i
            self.data[n], self.data[smallpos] = self.data[smallpos], self.data[n]

    def bubblesort(self):
        l = len(self.data)
        while True:
            swap = 0
            print(self.data)
            for i in range(0, l - 1):
                self.__plot()
                if self.data[i] > self.data[i + 1]:
                    self.data[i], self.data[i + 1] = self.data[i + 1], self.data[i]
                    swap = True
            if swap:
                continue
            else:
                break

    def quicksort1(self):
        if len(self.data) <= 1:
            return self.data
        else:
            pivot = self.data[0]
            left = [x for x in self.data[1:] if x < pivot]
            left = VisualSorts(left)
            right = [x for x in self.data[1:] if x >= pivot]
            right = VisualSorts(right)
            results = left.quick_sort1(ax, canvas) + [pivot] + right.quick_sort1(ax, canvas)
            self.data = results
            self.__plot()
            return results

    def quicksort(self, start, end): #CIS => Compare, Increment (i), Swap (i & j)
        if start < end:
            pivot_index = self.__partition(start, end)
            self.__plot()
            print (self.data)
            self.quicksort(start, pivot_index - 1)  # Sort the left side
            self.quicksort(pivot_index + 1, end)  # Sort the right side

    def __partition(self, start, end):
        i = start - 1
        pivot = self.data[end]
        for j in range(start, end): #range will not include the last element which is the pivot
            if self.data[j] < pivot:
                i = i + 1 #i keeps track of the pivot's supposed position while j runs through the entire array
                self.data[i], self.data[j] = self.data[j], self.data[i] #swap the element to arrange the array
                
        #put the pivot in place
        self.data[i + 1], self.data[end] = self.data[end], self.data[i + 1]
        return i + 1

    def mergesort(self):
        self.__mergesort(self.data)

    def __mergesort(self, arr):
        
        self.__plot()
        if len(arr) <= 1:
            return arr
    
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
    
        self.__mergesort(left)
        self.__mergesort(right)
        VisualSorts.merge(left, right, arr)
        self.__plot()

    #make the merge function to be
    #accessible by the class rather than an instance of the class
    @staticmethod 
    def merge(left, right, arr):
        lsize = len(left)
        rsize = len(right)
        l, r, i = 0, 0, 0
        while l < lsize and r < rsize:
            if left[l] < right[r]:
                arr [i]= left[l]
                i+=1
                l+=1
            else:
                arr[i] = right[r]
                i+=1
                r+=1
        while l<lsize:
            arr[i] = left[l]
            i+=1
            l+=1
        while r<rsize:
            arr[i] = right[r]
            i+=1
            r+=1     

    def BFS(self):
        pass


    def dijkstra():

        def find_lowest_cost_node(costs):
            lowest_cost = float("inf")
            lowest_cost_node = None
            for node in costs: 
                cost = costs[node]
                if cost < lowest_cost and node not in processed:
                    lowest_cost = cost 
                    lowest_cost_node = node 
            return lowest_cost_node

        #keep an array of all processes nodes as you do not porcess a node more than once
        processed = []

        #Represent everey node, parent and cost
        #graph holds the relationship between the nodes and their neighbours
        graph  = {}
        ''' graph["start"] = {}
        graph["start"]["a"] = 6
        graph["start"]["b"] = 6 '''

        graph["a"] = {}
        graph["a"]["fin"] = 1

        graph["b"] = {}
        graph["b"]["a"] = 3
        graph["b"]["fin"] = 5

        graph ["fin"] =  {} 

        #costs is how long it takes to get to a node from the start
        costs = {}
        costs["a"] = 6
        costs["b"] = 2
        costs["fin"] = float("inf")

        #parent is the predecessor of every node 
        parents = {}
        parents["a"] = "start"
        parents["b"] = "start"
        parents["fin"] = None

        node = find_lowest_cost_node(costs) 
        while node is not None: #for each non-processed node
            neighbors = graph[node] #check for the neighbors of the node
            for n in neighbors.keys(): #for each neighbor; first round, n = A
                new_cost = costs[node] + neighbors[n] #calculate it's cost
                if  new_cost < costs[n]:
                    costs[n] = new_cost
                    parents[n] = node 
            processed.append(node)
            node = find_lowest_cost_node(costs)

        def find_the_path(node):
            path = []
            while node != "start":
                parent = parents[node]
                path.append(parent)
                node = parent
            print(path)

        find_the_path("fin")

        dijkstra()         

    def DFS():
        pass

    def binarySearch():
        pass