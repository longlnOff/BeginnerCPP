// Exercise 12-7. Modify the Package class in the solution of Exercise 12-6 so that it contains 
// an additional pointer to the previous object in the list. This makes it a so-called doubly-linked 
// list—naturally, the data structure we were using before is called a singly-linked list. Modify the 
// Package, Truckload, and Iterator classes to make use of this, including providing the ability 
// to iterate through Box objects in the list in reverse order and to list the objects in a Truckload
// object in reverse sequence. Devise a main() program to demonstrate the new capabilities.

#include <iostream>
#include <format>
#include <vector>
#include <memory>


class Box
{
    public:
        // Constructor
        Box(const float &length, const float &width, const float &height) : m_length {length}, m_width {width}, m_height {height} {};

        // Delegating Constructor
        explicit Box(const float &side) : Box(side, side, side) {};
        explicit Box() : Box(1.0) {};

        // Destructor
        ~Box() = default;

        // Copy Constructor
        Box(const Box &box) : m_length {box.m_length}, m_width {box.m_width}, m_height {box.m_height} {};

        // Calculate volume
        double volume() const { return m_length * m_width * m_height; };

        // Compare
        int compare (const Box &box) const { return volume() < box.volume() ? -1 : volume() == box.volume() ? 0 : 1; };

        // List box
        void listBox() const {std::cout << std::format("Box({:.1f}, {:.1f}, {:.1f})\n", m_length, m_width, m_height);};

    private:
        float m_length {};
        float m_width {};
        float m_height {};
};

using SharedBox = std::shared_ptr<Box>;

class TruckLoad
{
    public:
        // Default constructor
        TruckLoad() = default;
        // Degelating constructor
        TruckLoad(SharedBox box) {m_head = m_tail = new Package(box);};
        TruckLoad(std::vector<SharedBox>& boxes);

        // Copy constructor
        TruckLoad(const TruckLoad &src);

        // Destructor
        ~TruckLoad() {delete m_head;};

        // Add a new SharedBox
        void addBox(SharedBox box);   

        // Remove a Box from the TruckLoad    
        bool removeBox(SharedBox box);  

        // Output the Boxes
        void listBoxes() const;   
        void listBoxesReversed() const;             


        // Iterator
        class Iterator;
        Iterator GetIterator() const;

    private:
        class Package
        {
            public:
                // Contructor
                explicit Package(SharedBox const &box) : m_box {box}, m_next {nullptr}, m_prev {nullptr} {};

                // Destructor
                ~Package() {delete m_next;};

                SharedBox GetBox() const {return m_box;};
                Package* GetNext() const {return m_next;};
                Package* GetPrev() const {return m_prev;};


                void SetNext(Package* package) {m_next = package;};
                void SetPrev(Package* package) {m_prev = package;};


                // Varible (Because Package is private class -> member variables can be public)
                SharedBox m_box {};
                Package *m_next {};
                Package *m_prev {};
        };

        Package *m_head {};
        Package *m_tail {};

};


class TruckLoad::Iterator
{
    public:
        SharedBox GetFirstBox();
        SharedBox GetNextBox();
        SharedBox GetLastBox();
        SharedBox GetPrevBox();


    private:
        Package *m_head {};
        Package *m_tail {};
        Package *m_current {};
        friend class TruckLoad;         // Allow TruckLoad access private members in Iterator
        explicit Iterator(Package *head, Package *tail) : m_head {head}, m_tail {tail}, m_current {nullptr} {};
};


SharedBox TruckLoad::Iterator::GetFirstBox()
{
    m_current = m_head;
    return m_current ? m_current->GetBox() : nullptr;
}

SharedBox TruckLoad::Iterator::GetLastBox()
{
    m_current = m_tail;
    return m_current ? m_current->GetBox() : nullptr;
}

SharedBox TruckLoad::Iterator::GetNextBox()
{
    if (!m_current)
        return GetFirstBox();
    m_current = m_current->m_next;
    return m_current ? m_current->GetBox() : nullptr;
}

SharedBox TruckLoad::Iterator::GetPrevBox()
{
    if (!m_current)
        return GetLastBox();
    m_current = m_current->m_prev;
    return m_current ? m_current->GetBox() : nullptr;
}



TruckLoad::TruckLoad(std::vector<SharedBox>& boxes)
{
    for (auto i : boxes)
        addBox(i);
}

// Copy constructor
TruckLoad::TruckLoad(const TruckLoad &src)
{
    for (Package *package {m_head}; package; package = package->m_next)
        addBox(package->m_box);
}


// Add a new SharedBox
void TruckLoad::addBox(SharedBox box)
{
    auto package {new Package(box)};
    if (m_tail)
    {
        m_tail->SetNext(package);
        package->SetPrev(m_tail);
    }
    else        // List is empty
        m_head = package;
    m_tail = package;
} 

// Remove a Box from the TruckLoad    
bool TruckLoad::removeBox(SharedBox box)
{
    Package *previous {nullptr};
    Package *current {m_head};

    while (true)
    {
        if (current->GetBox() == box)
        {
            // Udpate previous
            if (previous)
            {
                current->GetNext()->SetPrev(previous);
                previous->SetNext(current->GetNext());
            }

            // Update head
            if (current == m_head)
            {
                current->GetNext()->SetPrev(nullptr);
                m_head = current->GetNext();
            }

            // Update tail
            if (current == m_tail)
            {
                previous->SetNext(nullptr);
                m_tail = previous;
            }

            delete current;

            return true;
        }
        previous = current;
        current = current->GetNext();
    }

    return false;
}

// Output the Boxes
void TruckLoad::listBoxes() const
{
    const size_t BoxPerLine {4};
    size_t count {0};
    Package *currentPakage {m_head};
    while (currentPakage)
    {
        currentPakage->GetBox()->listBox();
        if (++count % BoxPerLine)
            std::cout << std::endl;
        // Move to next object
        currentPakage = currentPakage->GetNext();
    }
    std::cout << std::endl;
}  

void TruckLoad::listBoxesReversed() const       
{
    const size_t BoxPerLine {4};
    size_t count {0};
    Package *currentPakage {m_tail};
    while (currentPakage)
    {
        currentPakage->GetBox()->listBox();
        if (++count % BoxPerLine)
            std::cout << std::endl;
        // Move to next object
        currentPakage = currentPakage->GetPrev();
    }
    std::cout << std::endl;
}  

TruckLoad::Iterator TruckLoad::GetIterator() const
{
    return Iterator(m_head, m_tail);
}


SharedBox findLargestBox(const TruckLoad& TruckLoad)
{
    auto iterator {TruckLoad.GetIterator()};
    SharedBox LargestBox {iterator.GetFirstBox()};
    SharedBox nextBox{ iterator.GetNextBox() };
    while (nextBox)
    {
        if (nextBox->compare(*LargestBox) > 0)
            LargestBox = nextBox;
        nextBox = iterator.GetNextBox();
    }

    return LargestBox;
}
SharedBox findSmallestBox(const TruckLoad& TruckLoad)
{
    auto iterator {TruckLoad.GetIterator()};
    SharedBox SmallestBox {iterator.GetFirstBox()};
    SharedBox nextBox {iterator.GetNextBox()};

    while (nextBox)
    {
        if (nextBox->compare(*SmallestBox) < 0)
            SmallestBox = nextBox;
        nextBox = iterator.GetNextBox();
    }

    return SmallestBox;
}

#include <random>
#include <functional>


auto createUniformPseudoRandomNumberGenerator(double max)
{
    std::random_device seeder; // True random number generator to obtain a seed (slow)
    std::default_random_engine generator{seeder()}; // Efficient pseudo-random generator
    std::uniform_real_distribution distribution{0.0, max}; // Generate in [0, max) interval
    return std::bind(distribution, generator); //... and in the darkness bind them!
}

Box randomBox()
{
    const int dimLimit {100}; // Upper limit on Box dimensions
    static auto random{ createUniformPseudoRandomNumberGenerator(dimLimit) };
    return Box{ static_cast<float>(random()), static_cast<float>(random()), static_cast<float>(random()) };
}

auto randomSharedBox()
{
    return std::make_shared<Box>(randomBox()); // Uses copy constructor
}


int main()
{
    TruckLoad load;  // Create an empty list

    // Add 12 random Box objects to the list
    const size_t boxCount{ 12 };
    for (size_t i{}; i < boxCount; ++i)
    load.addBox(randomSharedBox());

    std::cout << "The random truckload:\n";
    load.listBoxes();
    std::cout << std::endl;

    std::cout << "The same random truckload in reverse:\n";
    load.listBoxesReversed();
    std::cout << std::endl;

    std::cout << "The largest box (found using forward iteration) is ";
    findLargestBox(load)->listBox();
    std::cout << std::endl;

    std::cout << "The smallest box (found using reverse iteration) is ";
    findSmallestBox(load)->listBox();
    std::cout << std::endl;
}