function removeDuplicatArr(items){
	return items.filter((item, idx) => items.indexOf(item) === idx)
}
