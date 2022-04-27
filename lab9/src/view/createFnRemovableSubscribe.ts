
function createFnRemovableSubscribe<T extends Event>(element: Element, type: string, fn: (event: T) => void): () => void {
	element.addEventListener(type, fn)
	return () => element.removeEventListener(type, fn)
}

export {
	createFnRemovableSubscribe,
}