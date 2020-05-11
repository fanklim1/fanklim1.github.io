  window.onload = function any_function_name()
{
let test = document.querySelector('#test');

let questions = [
	{
		text: 'Question 1?',
		right: 0,
		answers: ['answer1', 'answer2', 'answer3',]
	},
	{
		text: 'Question 2?',
		right: 1,
		answers: ['answer1', 'answer2', 'answer3',]
	},
	{
		text: 'Question 3?',
		right: 2,
		answers: ['answer1', 'answer2', 'answer3',]
	},
];

let i = 1;
for (let question of questions) {
	let div = document.createElement('div');
	test.appendChild(div);
	
	let p = document.createElement('p');
	p.innerHTML = question.text;
	div.appendChild(p);
	
	let form = document.createElement('form');
	test.appendChild(form);
	form.dataset.right = question.right;
	
	let j = 0;
	for (let answer of question.answers) {
		let input = document.createElement('input');
		input.type = 'radio';
		input.name = i;
		input.dataset.answerNum = j++;
		form.appendChild(input);
	}
	
	i++;
}

let button = document.querySelector('#button');
button.addEventListener('click', function() {
	let forms = document.querySelectorAll('#test form');
	
	for (let form of forms) {
		form.classList.remove('correct');
		form.classList.remove('incorrect');
		
		let inputs = form.querySelectorAll('input');
		
		for (let input of inputs) {
			if (input.checked) {
				if (input.dataset.answerNum == form.dataset.right) {
					form.classList.add('correct');
				} else {
					form.classList.add('incorrect');
				}
				
				break;
			}
		}
	}
});
}