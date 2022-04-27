function upload(onUpload: (value: string) => void) {
	const input = document.createElement('input')
	input.setAttribute('type', 'file')
	input.click()
	input.addEventListener('change', () => {
		const selectedFile = input.files && input.files[0]
		selectedFile.text().then(value => {
			onUpload(value)
		})
	}, {
		once: true,
	})
}

export {
	upload,
}