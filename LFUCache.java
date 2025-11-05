import java.util.*;

class LFUCache {
    int cap, min;
    Map<Integer, Integer> valMap;
    Map<Integer, Integer> freqMap;
    Map<Integer, LinkedHashSet<Integer>> freqList;

    public LFUCache(int capacity) {
        cap = capacity;
        min = 0;
        valMap = new HashMap<>();
        freqMap = new HashMap<>();
        freqList = new HashMap<>();
    }

    public int get(int key) {
        if (!valMap.containsKey(key)) return -1;
        int f = freqMap.get(key);
        freqMap.put(key, f + 1);
        freqList.get(f).remove(key);
        freqList.computeIfAbsent(f + 1, x -> new LinkedHashSet<>()).add(key);
        if (freqList.get(f).isEmpty()) {
            freqList.remove(f);
            if (min == f) min++;
        }
        return valMap.get(key);
    }

    public void put(int key, int val) {
        if (cap == 0) return;
        if (valMap.containsKey(key)) {
            valMap.put(key, val);
            get(key);
            return;
        }
        if (valMap.size() >= cap) {
            int old = freqList.get(min).iterator().next();
            freqList.get(min).remove(old);
            if (freqList.get(min).isEmpty()) freqList.remove(min);
            valMap.remove(old);
            freqMap.remove(old);
        }
        valMap.put(key, val);
        freqMap.put(key, 1);
        freqList.computeIfAbsent(1, x -> new LinkedHashSet<>()).add(key);
        min = 1;
    }
}
