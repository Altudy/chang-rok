const toDoForm = document.querySelector('.js-toDoForm');
toDoInput = toDoForm.querySelector("input");
toDoList = document.querySelector('.js-toDoList');

const TODOS_LS = "toDos";

// todo 목록을 담을 array
let toDos = [];


function deleteToDo(event) {
  const btn = event.target;
  const li = btn.parentNode;
  toDoList.removeChild(li);
  const cleanToDos = toDos.filter(function(toDo) {
    return toDo.id !== parseInt(li.id);
  });
  toDos = cleanToDos;
  saveToDos(toDos);
}
// localStorage에 배열 저장하는데 String으로 저장해야하므로 JSON.stringify를 씀.
function saveToDos(arr) {
  localStorage.setItem(TODOS_LS, JSON.stringify(arr));
}
// createElement를 이용해서 ul 밑에 li추가.
function paintToDo(text) {
  const li = document.createElement('li');
  const delBtn = document.createElement('button');
  delBtn.innerText = "❌";
  delBtn.addEventListener("click", deleteToDo);
  const span = document.createElement('span');
  const newId = toDos.length + 1;
  span.innerText = text;
  li.appendChild(span);
  li.appendChild(delBtn);
  li.id = newId;
  toDoList.appendChild(li);
  // 적은 todo를 id 값과 같이 object로 만들어서 toDos에 넣기 위함.
  const toDoObj = {
    text: text,
    id: newId
  };
  toDos.push(toDoObj);
  saveToDos(toDos);
}

function handleSubmit(event) {
  //submit 막기 위해
  event.preventDefault();
  // input에 입력한 text값 가져옴.
  const currentValue = toDoInput.value;
  paintToDo(currentValue);
  toDoInput.value = "";
}

function loadToDos() {
  const loadedToDos = localStorage.getItem(TODOS_LS);
  // todo목록이 있다면
  if (loadedToDos !== null) {
    // String으로부터 Object로 파싱.
    const parsedToDos = JSON.parse(loadedToDos);
    // 루프를 돌면서 paintToDo 함수를 통해 화면에 출력.
    parsedToDos.forEach((todo) => {
      paintToDo(todo.text);
    });
  }
}

function init() {
  loadToDos();
  toDoForm.addEventListener("submit", handleSubmit);
}

init();
