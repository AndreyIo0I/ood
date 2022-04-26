
type Listener<T> = (value: T) => void

class Signal<T> {
	private listeners: Array<Listener<T>> = []

	dispatch(value: T): void {
		this.listeners.forEach(listener => listener(value))
	}

	add(listener: Listener<T>): () => void {
		this.listeners.push(listener)
		return () => this.remove(listener)
	}

	addCallOnce(listener: Listener<T>): void {
		const callOnceFn = (value: T) => {
			listener(value)
			this.remove(callOnceFn)
		}
		this.add(callOnceFn)
	}

	remove(listener: Listener<T>): void {
		this.listeners = this.listeners.filter(v => v !== listener)
	}

	removeAll(): void {
		this.listeners = []
	}
}

export {
	Signal,
}