template <typename T>
class Stack
{
public:

    Stack()
    {
        head_ = nullptr;
        size_ = 0;
    }

    ~Stack() = default;

    int size()
    {
        return size_;
    }

    bool isEmpty()
    {
        return (size() == 0);
    }

    T top()
    {
        if (isEmpty()) {
            return T();
        } else {
            return head_->data_;
        }
    }

    void push(T value)
    {
        Node *new_node = new Node(value);
        if (!isEmpty()) {
            new_node->next_ = head_;
        }
        head_ = new_node;
        size_++;
    }

    void pop()
    {
        if (isEmpty()) {
            return;
        }
        head_ = head_->next_;
        size_--;
    }

private:

    class Node
    {
    public:

        Node(T value)
        {
            next_ = nullptr;
            data_ = value;
        }

        ~Node() = default;
        Node *next_;
        T data_;
    };

    Node *head_;
    int size_;
    
};