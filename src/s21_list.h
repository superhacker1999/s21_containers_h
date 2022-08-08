template <typename T> class node_list {
    private:
        typedef struct node_ {
            T data_;
            struct node_ *next;
            struct node_ *prev;
        } node_;
};



// namespace s21 {
template <typename T> class s21_list::<T>node_list {
            int size_;
            int capacity_;
            node_* head_;
            node_* tail_;

        public:
            s21_list();
            s21_list(int size);
            void s21_list::push_front(template <typename T> data);

    };
// }
