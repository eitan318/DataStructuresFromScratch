#ifndef IBINARYTREE_H
#define IBINARYTREE_H

#include <optional>

template <typename T, typename ReturnType>
class IBinaryTree {
public:
    virtual void insert(T value) = 0;
    virtual void remove(T value) = 0;
    virtual void in_order_traversal() = 0;
    virtual void pre_order_traversal() = 0;
    virtual void post_order_traversal() = 0;
    virtual void level_order_traversal() = 0;
    virtual T find_min() = 0;
    virtual T find_max() = 0;
    virtual int height() = 0;
    virtual int size() = 0;
    virtual bool is_empty() = 0;
    std::optional<ReturnType> search(T value) override;  // Templated search method
};

#endif // IBINARYTREE_H