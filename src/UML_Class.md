````mermaid
classDiagram
      class Sorter {
          <<abstract>>
          +sort(array : vector~int~) vector~Step~*
          +getName() string*
      }

      class BubbleSorter {
          +sort(array : vector~int~) vector~Step~
          +getName() string
      }

      class SelectionSorter {
          +sort(array : vector~int~) vector~Step~
          +getName() string
      }

      class InsertionSorter {
          +sort(array : vector~int~) vector~Step~
          +getName() string
      }

      class QuickSorter {
          +sort(array : vector~int~) vector~Step~
          +getName() string
          -partition(array, left, right, steps, sorted, compare_count, swap_count) int
          -sort_recursive(array, left, right, steps, sorted, compare_count, swap_count) void
      }

      class MergeSorter {
          +sort(array : vector~int~) vector~Step~
          +getName() string
          -merge(array, left, middle, right, compare_count, swap_count, steps, sorted) void
          -sort_recursive(array, left, right, compare_count, swap_count, steps, sorted) void
      }

      class Step {
          +array : vector~int~
          +compare_left : int
          +compare_right : int
          +swap_left : int
          +swap_right : int
          +sorted : vector~bool~
          +compare_count : int
          +swap_count : int
      }

      class Visualizer {
          +play(steps : vector~Step~, title : string) void
          -draw_frame(step : Step, title : string, current_step : int, total_steps : int) void
      }

      class SortApp {
          -visualizer : Visualizer
          +run() void
          -select_algorithm() unique_ptr~Sorter~
          -select_size() int
          -generate_array(size : int) vector~int~
      }

      Sorter <|-- BubbleSorter
      Sorter <|-- SelectionSorter
      Sorter <|-- InsertionSorter
      Sorter <|-- QuickSorter
      Sorter <|-- MergeSorter

      Sorter ..> Step : creates
      Visualizer ..> Step : uses
      SortApp --> Sorter : uses
      SortApp *-- Visualizer : has
````