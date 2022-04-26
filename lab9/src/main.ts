import {EditorView} from './view/EditorView'
import {EditorVM} from './viewModel/EditorVM'
import {Canvas} from './domain/Canvas'

window.addEventListener('DOMContentLoaded', initEditor)

function initEditor() {
	const canvasModel = new Canvas()
	const editorView = new EditorView()
	new EditorVM(canvasModel, editorView)

	editorView.render(document.body)
}
