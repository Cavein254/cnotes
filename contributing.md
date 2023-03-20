# :computer: HOW TO CONTRIBUTE :rocket: :vulcan_salute: :firefighter:

I'm really glad you're reading this, because we need volunteer developers to help this project a success.

The goal is to make informative notes on the c language that can benefit all of us in the course of our learning.

## GETTING STARTED :walking:

### STEP 1: Sign In to Github

Sign into your GibHub or [create a free GitHub account](https://www.github.com/) if you lack one.

### STEP 2: Fork the project repository

Find the project's repository on GitHub, and then "fork" it by clicking the Fork button in the upper right corner:

### STEP 3: Clone your folk :fork_and_knife:

Using Git on your local machine, clone your fork using the URL you just copied: `git clone URL_OF_FORK`.

### Step 4: Navigate to your local repository :house:

Since the clone was downloaded into a subdirectory of your working directory, you can navigate to it using: cd `NAME_OF_REPOSITORY`.

### Step 5: Check that your fork is the "origin" remote :fork_and_knife:

You are going to be synchronizing your local repository with both the project repository (on GitHub) and your fork (also on GitHub).

```bash
git remote -v
```
You should see the URL of your fork (which you copied in step 3) next to the word "origin".


### Step 6: Add the project repository as the "upstream" remote :cloud:

Add the project repository as the "upstream" remote using: git remote add upstream `URL_OF_PROJECT`.

```bash
git remote add https://github.com/Cavein254/cnotes.git

```

### Step 7: Pull the latest changes from upstream into your local repository

Before you start making any changes to your local files, it's a good practice to first synchronize your local repository with the project repository. 

```bash
git pull upstream master 
```

### Step 8: Create a new branch :star2:

Rather than making changes to the project's "main" branch, it's a good practice to instead create your own branch. This creates an environment for your work that is isolated from the master branch.

**The name of the branch should briefly describe what you are working on, and should not contain any spaces**

```bash
git checkout -b doc-fixes
```

### Step 9: Make changes in your local repository :computer:

Now you can make changes to your branch

### Step 10: Commit your changes :computer:

```bash
git commit -m "fix typos in set_config docstring"
```

### Step 11: Push your changes to your fork

When you are done making all of your changes, upload these changes to your fork using git push origin BRANCH_NAME.

```bash
git push origin doc-fixes
```

### Step 12: Begin the pull request

Return to your fork on GitHub, and refresh the page. You may see `Compare & pull request` green button. Click on it.

### Step 13: Create the pull request :man_firefighter:

Write a descriptive title for your pull request, and then include more details in the body of the pull request. If there are any related GitHub issues, make sure to mention those by number.

### Spep 14: Finalizing :heart_decoration: :firefighter: :rocket:

After creating the pull request edit the `README.md` file on the author section and add your details as an author.