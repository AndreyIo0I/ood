
class ButtonView {
	private readonly element: HTMLElement

	constructor(onClick: () => void, className: string) {
		this.element = document.createElement('div')
		this.element.classList.add('button', className)
		this.element.addEventListener('click', () => onClick())
	}

	getElement(): HTMLElement {
		return this.element
	}

	render(parent: HTMLElement) {
		parent.appendChild(this.getElement())
	}
}

export {
	ButtonView,
}