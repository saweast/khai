var cnt_1 = document.getElementById('main_cnt'),
	cnt_2 = document.getElementById('resume_cnt'),
	cnt_3 = document.getElementById('contact_cnt'),
	cnt_4 = document.getElementById('blog_cnt'),
	m_but_1 = document.getElementById('open_main'),
	m_but_2 = document.getElementById('open_resume'),
	m_but_3 = document.getElementById('open_contact'),
	m_but_4 = document.getElementById('open_blog');

open_main.addEventListener('click', function() {
	cnt_1.style.display = "inline-block";
	cnt_2.style.display = "none";
	cnt_3.style.display = "none";
	cnt_4.style.display = "none";
});

open_resume.addEventListener('click', function() {
	cnt_1.style.display = "none";
	cnt_2.style.display = "inline-block";
	cnt_3.style.display = "none";
	cnt_4.style.display = "none";
});

open_contact.addEventListener('click', function() {
	cnt_1.style.display = "none";
	cnt_2.style.display = "none";
	cnt_3.style.display = "inline-block";
	cnt_4.style.display = "none";
});

open_blog.addEventListener('click', function() {
	cnt_1.style.display = "none";
	cnt_2.style.display = "none";
	cnt_3.style.display = "none";
	cnt_4.style.display = "inline-block";
});