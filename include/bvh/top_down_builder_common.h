#ifndef BVH_BUILDERS_TOP_DOWN_BUILDER_COMMON_H
#define BVH_BUILDERS_TOP_DOWN_BUILDER_COMMON_H

#include <cstddef>

namespace bvh {

/// Configuration parameters for the builder, with default values that should work for most uses.
template <typename T>
struct TopDownBuilderConfig {
    /// Maximum allowed BVH depth.
    size_t max_depth = 64;

    /// The algorithm stops when there are as many or fewer primitives in the current range.
    size_t min_prims_per_leaf = 1;

    /// The algorithm makes sure that there are not more than this many
    /// primitives per leaf, by using a fallback strategy for bad splits.
    size_t max_prims_per_leaf = 8;

    /// Cost of traversing a node, expressed with respect to the cost of intersecting a primitive.
    /// For instance, a cost of 2 would mean that traversing a node is twice as slow as
    /// intersecting a primitive.
    T traversal_cost = T(1.0);
};

/// Base class for all top-down schedulers. Top-down schedulers are objects that controls how
/// a top-down construction algorithm is executed. Custom top-down schedulers can be implemented
/// to support various parallel libraries or frameworks.
template <typename Builder>
struct TopDownScheduler {
    using InnerTask = typename Builder::Task;
    using WorkItem  = typename Builder::WorkItem;
};

} // namespace bvh

#endif