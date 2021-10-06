(ns sort.core-test
  (:require [clojure.test :refer :all]
            [sort.core :refer :all]))

(deftest a-test
  (testing "Woohooo"
    (is (= nil (quick-sort []))
    (is (= nil (quick-sort []))
    (is (= [0] (quick-sort [0]))
    (is (= [0 1 2] (quick-sort [0 1 2])))
    (is (= [0 1 2] (quick-sort [2 1 0])))
    (is (= [1 2 8] (quick-sort [2 8 1])))
    (is (= [-5 0 9] (quick-sort [0 -5 9]))))))
