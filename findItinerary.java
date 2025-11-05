import java.util.AbstractList;

class findItinerary {
  public List<String> findItinerary(List<List<String>> tickets) {
    return wrapper(tickets);
  }

  private List<String> heirholzer(List<List<String>> tickets) {
    Map<String, PriorityQueue<String>> graph = new HashMap<>();
    for(List<String> ticket: tickets) {
      graph.computeIfAbsent(ticket.getFirst(), k -> new PriorityQueue<>()).add(ticket.getLast());
    }

    List<String> route = new LinkedList<>();
    visit(graph, "JFK", route);

    return route;
  }

  private void visit(Map<String, PriorityQueue<String>> graph, String airport, List<String> route) {
    PriorityQueue<String> queue = graph.get(airport);

    while (queue != null && !queue.isEmpty()) {
      visit(graph, queue.poll(), route);
    }

    route.addFirst(airport);
  }

  private List<String> wrapper(List<List<String>> tickets) {
    return new AbstractList<String>() {
      List<String> res;

      public int size() {
        if(res == null) {
          init();
        }

        return res.size();
      }

      public String get(int i) {
        if(res == null) {
          init();
        }

        return res.get(i);
      }

      private void init() {
        res = heirholzer(tickets);
      }
    };
  }
}