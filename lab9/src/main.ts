import {EditorPresenter} from './presenter/EditorPresenter'

//todo синхронизировать курсор с точкой
window.addEventListener('DOMContentLoaded', initEditor)

function initEditor() {
	new EditorPresenter()
}
