// Exercise 12-6. Finish the nested TruckLoad::Iterator class that we started at the end of the 
// chapter. Starting from Ex12_18, add the Iterator class to its definition as listed earlier and 
// implement its member functions. Use the Iterator class to implement the findLargestBox()
// function as outlined earlier (perhaps you can do it without looking at the solution?) and 
// rework the main() function of Ex12_18 to make use of this. Do the same with an analogous 
// findSmallestBox() function.


#include <iostream>
#include <format>
#include <memory>
#include <vector>

class Box
{
    public:
        // Delegating constructor
        Box(const float& length, const float& height, const float& width) : m_length {length}, m_height {height}, m_width {width} {};
        Box(const float& x) : Box(x, x, x){};
        Box() : Box(1) {};

        // Detructor
        ~Box() = default;

        // Copy constructor
        Box(const Box& box) : Box(box.m_length, box.m_height, box.m_width){};

        double volume() const; 
        float compare(const Box& obj) const;
        void listBox() const;
    private:
        float m_length {};
        float m_height {};
        float m_width {};
};

double Box::volume() const
{
    return m_height * m_height * m_width;
}

float Box::compare(const Box& obj) const
{
    if (volume() < obj.volume())
        return -1;
    else if (volume() == obj.volume())
        return 0;
    else
        return 1;
}

void Box::listBox() const
{
    std::cout << std::format("Box({:.1f},{:.1f},{:.1f})\n", m_length, m_width, m_height);
}


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

        void addBox(SharedBox box);         // Add a new SharedBox
        bool removeBox(SharedBox box);      // Remove a Box from the TruckLoad
        void listBoxes() const;             // Output the Boxes

        // Iterator
        class Iterator;
        Iterator GetIterator() const;

    private:
        class Package
        {
            public:
                Package(SharedBox box) : m_box {box}, m_next {nullptr} {}
                ~Package() {delete m_next;}

                SharedBox GetBox() const {return m_box;};
                Package* GetNext() const {return m_next;};

                void SetNext(Package* package) {m_next = package;};
                Package *m_next;      
                SharedBox m_box;
        };
        Package* m_head {};
        Package* m_tail {};
};

class TruckLoad::Iterator
{
    public:
        SharedBox getFirstBox();
        SharedBox getNextBox();

    private:
        Package* m_head;                                            // The head of the linked list (needed for getFirstBox())
        Package* m_current;                                         // The package whose Box was last retrieved
        friend class TruckLoad;                                     // Only a TruckLoad can create an Iterator
        explicit Iterator(Package* head) : m_head{head}, m_current{nullptr} {};
};


SharedBox TruckLoad::Iterator::getFirstBox()
{
    m_current = m_head;
    return m_current ? m_current->GetBox() : nullptr;
}


SharedBox TruckLoad::Iterator::getNextBox()
{
    if (!m_current)
        return getFirstBox();
    m_current = m_current->m_next;

    return m_current ? m_current->GetBox() : nullptr;


}

TruckLoad::Iterator TruckLoad::GetIterator() const
{
    return Iterator {m_head};
}


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

TruckLoad::TruckLoad(const TruckLoad &src)
{
    for (Package* package{ src.m_head }; package; package = package->m_next)
    {
        addBox(package->m_box);
    }
}

TruckLoad::TruckLoad(std::vector<SharedBox>& boxes)
{
    for (auto box : boxes)
        addBox(box);
}


void TruckLoad::addBox(SharedBox box)
{
    auto package {new Package(box)};
    if (m_tail)
        m_tail->SetNext(package);
    else
        m_head = package;
    m_tail = package;
}


bool TruckLoad::removeBox(SharedBox box)
{
    Package *previous {nullptr};
    Package *current {m_head};

    while (true)
    {
        if (current->GetBox() == box)
        {
            if (previous)
                previous->SetNext(current->GetNext());
            // Update head
            if (current == m_head)
                m_head = current->GetNext();
            // Update tail
            if (current == m_tail)
                m_tail = previous;

            current->SetNext(nullptr);
            delete current;
            return true;
        }

        previous = current;
        current  = current->GetNext();
    }

    return false;
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


SharedBox findLargestBox(const TruckLoad& TruckLoad)
{
    auto iterator {TruckLoad.GetIterator()};
    SharedBox LargestBox {iterator.getFirstBox()};
    SharedBox nextBox{ iterator.getNextBox() };
    while (nextBox)
    {
        if (nextBox->compare(*LargestBox) > 0)
            LargestBox = nextBox;
        nextBox = iterator.getNextBox();
    }

    return LargestBox;
}
SharedBox findSmallestBox(const TruckLoad& TruckLoad)
{
    auto iterator {TruckLoad.GetIterator()};
    SharedBox SmallestBox {iterator.getFirstBox()};
    SharedBox nextBox {iterator.getNextBox()};

    while (nextBox)
    {
        if (nextBox->compare(*SmallestBox) < 0)
            SmallestBox = nextBox;
        nextBox = iterator.getNextBox();
    }

    return SmallestBox;
}

int main()
{
    TruckLoad load1;  // Create an empty list

    // Add 12 random Box objects to the list
    const size_t boxCount{ 12 };
    for (size_t i{}; i < boxCount; ++i)
        load1.addBox(randomSharedBox());

    std::cout << "The first list:\n";
    load1.listBoxes();

    // Copy the TruckLoad
    TruckLoad copy{ load1 };
    std::cout << "The copied TruckLoad:\n";
    copy.listBoxes();

    // Find the largest Box in the list
    const auto largestBox{ findLargestBox(load1) };

    std::cout << "\nThe largest box in the first list is ";
    largestBox->listBox();
    std::cout << std::endl;
    load1.removeBox(largestBox);
    std::cout << "\nAfter deleting the largest box, the list contains:\n";
    load1.listBoxes();

    const size_t nBoxes{ 20 };            // Number of vector elements
    std::vector<SharedBox> boxes;        // Array of Box objects

    for (size_t i{}; i < nBoxes; ++i)
        boxes.push_back(randomSharedBox());

    TruckLoad load2{ boxes };
    std::cout << "\nThe second list:\n";
    load2.listBoxes();

    const auto smallestBox{ findSmallestBox(load2) };

    std::cout << "\nThe smallest box in the second list is ";
    smallestBox->listBox();
    std::cout << std::endl;

    return 0;
}