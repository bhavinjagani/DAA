#include <iostream>
#include <vector>
#include <stdexcept>

/* Uncomment this code to use custom data type*/

// class Person {
// public:
//     std::string name;
//     int age;

//     Person(std::string n, int a) : name(n), age(a) {}

//     bool operator<(const Person& other) const {
//         return this->age < other.age;
//     }

//     friend std::ostream& operator<<(std::ostream& os, const Person& person) {
//         os << person.name << " (Age: " << person.age << ")";
//         return os;
//     }
// };

template <typename T>
class MinHeap
{
public:
    std::vector<T> heap;

    int parent(int index)
    {
        return (index - 1) >> 1;
    }

    int left(int index)
    {
        return (index << 1) + 1;
    }

    int right(int index)
    {
        return (index << 1) + 2;
    }

    void heapify_down(int index)
    {
        int leftChild = left(index);
        int rightChild = right(index);
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
        {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
        {
            smallest = rightChild;
        }

        if (smallest != index)
        {
            std::swap(heap[index], heap[smallest]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int index)
    {
        if (index && heap[parent(index)] > heap[index])
        {
            std::swap(heap[index], heap[parent(index)]);
            heapify_up(parent(index));
        }
    }

    void build_min_heap(const std::vector<T> &elements)
    {
        heap = elements;
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
        {
            heapify_down(i);
        }
    }

    void insert(T element)
    {
        heap.push_back(element);
        heapify_up(heap.size() - 1);
    }

    T pop_min()
    {
        if (heap.empty())
        {
            throw std::out_of_range("Heap is empty");
        }

        T root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
        {
            heapify_down(0);
        }

        return root;
    }

    T get_min() const
    {
        if (heap.empty())
        {
            throw std::out_of_range("Heap is empty");
        }

        return heap[0];
    }

    void print_heap() const
    {
        for (const auto &el : heap)
        {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    MinHeap<float> heap;

    std::vector<float> elements = {3.2, 1.3, 6.5, 5.9, 2.4, 8.9, 7.1};
    heap.build_min_heap(elements);
    std::cout << "Heap after build_min_heap: ";
    heap.print_heap();
    heap.insert(0.6);
    std::cout << "heapify after inserting 0.6: ";
    heap.print_heap();

    int minElement = heap.pop_min();
    std::cout << "Popped min element: " << minElement << std::endl;
    std::cout << "heapify after pop_min: ";
    heap.print_heap();

    return 0;
}
