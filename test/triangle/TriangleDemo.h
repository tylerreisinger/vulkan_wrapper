#ifndef TRIANGLEDEMO_H_
#define TRIANGLEDEMO_H_

#include <memory>

#include "Instance.h"

class TriangleDemo {
public:
    TriangleDemo();
    ~TriangleDemo();

    TriangleDemo(const TriangleDemo& other) = delete;
    TriangleDemo(TriangleDemo&& other) noexcept = delete;
    TriangleDemo& operator =(const TriangleDemo& other) = delete;
    TriangleDemo& operator =(TriangleDemo&& other) noexcept = delete;

    void run();

private:
    void initialize();

    void create_instance();

    std::unique_ptr<Instance> m_instance;
};

#endif
