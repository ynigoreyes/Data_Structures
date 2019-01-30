/**
 * Wrapper for an array that will decrease/increases size when needed
 *
 * Private Scope is default
 *
 * Size is the actual size of the array itself
 */
class ArrayList {
  int size, num_elements, *arr;
  public:
    ArrayList();
    ArrayList(int);
    ~ArrayList(); // Destructor

    int Get(int);
    void Set(int, int);

    void Insert(int, int);
    void Remove(int);
    void PrintList();
};
