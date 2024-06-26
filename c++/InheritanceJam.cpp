/*

Some experimentation with inheritance and polymorphism.

*/

using namespace std;

class BasicClass {
    private:
        int someValue;
    public:
        BasicClass() { };
        /*
        A basic constructor, where the value to be passed to the
        private variable is passed to the class and then to the
        internal variable that has to be assigned.
        */
        BasicClass(int val) : someValue(val) { };
};

class DerivedClass {
    private:
        int someOtherValue;
    public:
        DerivedClass() { };
};

template <typename T>
class TestBaseClass {
    private:
        T someData;
    public:
        /*
        For the case of template classes, the follow basic constructor
        just sets the value for someData to null. An easier way to
        think of this is T() essentially casting whatever may be
        passed to it.
        */
        TestBaseClass() : someData(T()) { };

        /*
        In the constructor below, notice that val is directly
        assigned to someData, instead of having a T between as
        for the previous case. This is because a T would be
        rather redundant, as val would first be assigned to a temp
        T, and then assigned to the internal variable someData.
        Also compare this with the BasicClass constructor.
        */
        TestBaseClass(T val) : someData(val) { };
};

template <typename T>
class TestDerivedClass : TestBaseClass<T> {
    private:
        T someAdditionalData;
    public:
        TestDerivedClass() : someAdditionalData(T()) { };
        /*
        This constructor list is responsible for setting the base
        class' internal variable by passing baseVal to the base
        class' constructor and also using <T> to ensure the base
        class undertands what type we are dealing with. And second
        in the list is the derived class' interval variable which
        is being set using standard method of passing the value to
        the variable.
        */
        TestDerivedClass(T val, T baseVal) : TestBaseClass<T>(baseVal), 
            someAdditionalData(val) { };
};

int main() {
    BasicClass testClass1(47);
}


