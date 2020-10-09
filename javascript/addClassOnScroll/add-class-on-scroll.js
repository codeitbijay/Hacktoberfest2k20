const data = [];

// function for defining class of elements to select, class to add, and offset (in pixels)
const addElements = (classToSelect, classToAdd, offset = 0) => {
  const elementData = {
    classToSelect,
    classToAdd,
    offset,
  };
  data.push(elementData);
};


// adds class on scroll to elements specified in data array
const adClassOnScroll = () => {
  // selects given elements
  const nodeListArr = data.map(entry =>
    document.querySelectorAll(`.${entry.classToSelect}`)
  );

  // calculate elements positions
  const positions = nodeListArr.map(list =>
    Array.from(list).map(el => el.getBoundingClientRect().y)
  );

  window.addEventListener('scroll', () => {
    let scrollPosition = window.pageYOffset;
    nodeListArr.forEach((list, listIndex) => {
      list.forEach((element, elementIndex) => {
        if (
          scrollPosition + data[listIndex].offset >
          positions[listIndex][elementIndex]
        ) {
          element.classList.add(data[listIndex].classToAdd);
        }
      });
    });
  });
};
