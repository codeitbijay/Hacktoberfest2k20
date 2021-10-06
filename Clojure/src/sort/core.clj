(ns sort.core
  (:gen-class))

(defn quick-sort [[pivot & coll]]
  (when pivot
    (concat (quick-sort (filter #(< % pivot) coll))
            [pivot]
            (quick-sort (filter #(>= % pivot) coll)))))

(defn -main
  "I will call quick-sort"
  [& args]
  (let [unsorted [3 2 1 4 7]]
    (println "Hello, Quick-Sort:")
    (println "Input:  " unsorted)
    (println "Output: " (quick-sort unsorted))))
