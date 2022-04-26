import path from 'path'
import {fileURLToPath} from 'url'

const __dirname = path.dirname(fileURLToPath(import.meta.url));

export default {
	entry: './src/main.ts',
	mode: 'development',
	module: {
		rules: [
			{
				use: 'ts-loader',
				test: /\.ts$/,
				exclude: /node_modules/,
			},
		],
	},
	resolve: {
		extensions: ['.ts', '.js'],
	},
	output: {
		filename: 'index.js',
		path: __dirname,
	},
}
