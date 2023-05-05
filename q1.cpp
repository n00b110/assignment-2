class Single_Linked_List:
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None
    
    def __init__(self):
        self.head = None
        self.tail = None
        self.num_items = 0
    
    def is_empty(self):
        return self.num_items == 0
    
    def size(self):
        return self.num_items
    
    def add_first(self, data):
        new_node = self.Node(data)
        if self.is_empty():
            self.tail = new_node
        else:
            new_node.next = self.head
        self.head = new_node
        self.num_items += 1
    
    def add_last(self, data):
        new_node = self.Node(data)
        if self.is_empty():
            self.head = new_node
        else:
            self.tail.next = new_node
        self.tail = new_node
        self.num_items += 1
    
    def remove_first(self):
        if self.is_empty():
            raise Exception("List is empty")
        removed_node = self.head
        if self.head == self.tail:
            self.tail = None
        self.head = self.head.next
        self.num_items -= 1
        return removed_node.data
    
    def remove_last(self):
        if self.is_empty():
            raise Exception("List is empty")
        removed_node = self.tail
        if self.head == self.tail:
            self.head = None
        else:
            current_node = self.head
            while current_node.next != self.tail:
                current_node = current_node.next
            current_node.next = None
        self.tail = current_node
        self.num_items -= 1
        return removed_node.data
    
    def push_front(self, data):
        self.add_first(data)
    
    def push_back(self, data):
        self.add_last(data)
    
    def pop_front(self):
        return self.remove_first()
    
    def pop_back(self):
        return self.remove_last()
    
    def front(self):
        if self.is_empty():
            raise Exception("List is empty")
        return self.head.data
    
    def back(self):
        if self.is_empty():
            raise Exception("List is empty")
        return self.tail.data
    
    def find(self, item):
        current_node = self.head
        index = 0
        while current_node is not None:
            if current_node.data == item:
                return index
            current_node = current_node.next
            index += 1
        return -1
    
    def insert(self, index, item):
        if index < 0 or index > self.num_items:
            raise Exception("Invalid index")
        if index == 0:
            self.add_first(item)
        elif index == self.num_items:
            self.add_last(item)
        else:
            new_node = self.Node(item)
            current_node = self.head
            for _ in range(index - 1):
                current_node = current_node.next
            new_node.next = current_node.next
            current_node.next = new_node
            self.num_items += 1
    
    def empty(self):
        return self.is_empty()
    
    def display(self):
        current_node = self.head
        while current_node is not None:
            print(current_node.data, end=" ")
            current_node = current_node.next
        print()

